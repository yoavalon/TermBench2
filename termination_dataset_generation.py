import os
import re
import ast
import json
import time
import random
import hashlib
import requests
import multiprocessing

# ==========================================
# 1. CONFIGURATION
# ==========================================
OLLAMA_URL = "http://localhost:11434/api/chat"
MODEL = "qwen2.5-coder:14b"
TIMEOUT_SECONDS = 2.0
SAMPLES_PER_LENGTH = 100 

CATEGORIES = [
    "boundary_conditions",
    "recursion",
    "data_mutations",
    "floating_point_precision",
    "mathematical_sequences"
]

LENGTHS = ["short", "medium", "long"]
DATASET_ROOT = os.path.join("dataset", "python")

DOMAINS = [
    "graph traversal and shortest path routing",
    "thermodynamic state simulations",
    "financial Monte Carlo option pricing models",
    "biostatistical p-value permutations",
    "cryptographic hashing and cipher simulations",
    "temporal frame sequence tracking",
    "flight trajectory and cruise altitude planning",
    "3D coordinate geometry transformations",
    "document parsing and lexical tokenization",
    "natural language processing vectorization",
    "fluid dynamics via cellular automata",
    "abstract syntax tree semantic linting",
    "supply chain logistics optimization",
    "neural network forward pass matrix operations",
    "genomic sequence alignment algorithms",
    "decentralized ledger consensus mechanics",
    "digital signal processing",
    "reinforcement learning reward decay",
    "state machines for network connections",
    "particle swarm optimization algorithms"
]

# ==========================================
# 2. FILE SYSTEM & AST VALIDATION
# ==========================================
def setup_directories():
    os.makedirs(DATASET_ROOT, exist_ok=True)

class SkeletonVisitor(ast.NodeVisitor):
    def __init__(self):
        self.skeleton = []
    
    def generic_visit(self, node):
        if not isinstance(node, (ast.Name, ast.Constant, ast.Load, ast.Store, ast.alias)):
            self.skeleton.append(type(node).__name__)
        super().generic_visit(node)

def get_ast_skeleton_hash(code_string: str) -> str:
    parsed_ast = ast.parse(code_string)
    visitor = SkeletonVisitor()
    visitor.visit(parsed_ast)
    return hashlib.md5(",".join(visitor.skeleton).encode()).hexdigest()

def extract_metrics(code_string: str) -> dict:
    """Calculates AST size, cyclomatic complexity, and loops."""
    parsed = ast.parse(code_string)
    nodes = list(ast.walk(parsed))
    ast_nodes_count = len(nodes)
    
    # Estimate CFG nodes (basic blocks roughly track with statements + expressions)
    cfg_nodes_count = sum(1 for n in nodes if isinstance(n, (ast.stmt, ast.expr)))
    
    # Cyclomatic Complexity (Base 1 + decision points)
    cc = 1
    loops = 0
    funcs = 0
    
    for node in nodes:
        if isinstance(node, (ast.If, ast.For, ast.While, ast.ExceptHandler, ast.With)):
            cc += 1
        elif isinstance(node, ast.BoolOp):
            cc += len(node.values) - 1
            
        if isinstance(node, (ast.For, ast.While)):
            loops += 1
        if isinstance(node, (ast.FunctionDef, ast.AsyncFunctionDef)):
            funcs += 1
            
    return {
        "ast_nodes": ast_nodes_count,
        "cfg_nodes": cfg_nodes_count,
        "cyclomatic_complexity": cc,
        "loop_count": loops,
        "function_count": funcs
    }

def validate_code_structure(code_string: str, expected_length: str) -> tuple:
    try:
        parsed_ast = ast.parse(code_string)
    except SyntaxError as e:
        return False, code_string, 0, f"SyntaxError: {e}"

    has_func = any(isinstance(node, (ast.FunctionDef, ast.AsyncFunctionDef)) for node in ast.walk(parsed_ast))
    if not has_func:
        return False, code_string, 0, "Code must define and execute at least one function."

    clean_code = ast.unparse(parsed_ast)
    lines = [line for line in clean_code.splitlines() if line.strip()]
    line_count = len(lines)

    if expected_length == "short" and not (line_count < 15):
        return False, clean_code, line_count, f"Short code must be < 15 lines. Got {line_count}."
    elif expected_length == "medium" and not (15 <= line_count <= 30):
        return False, clean_code, line_count, f"Medium code must be 15-30 lines. Got {line_count}."
    elif expected_length == "long" and not (line_count > 30):
        return False, clean_code, line_count, f"Long code must be > 30 lines. Got {line_count}."

    return True, clean_code, line_count, ""

# ==========================================
# 3. LLM COMMUNICATION
# ==========================================
def ask_llm(system_prompt: str, user_prompt: str, temperature=0.8) -> str:
    payload = {
        "model": MODEL,
        "messages": [
            {"role": "system", "content": system_prompt},
            {"role": "user", "content": user_prompt}
        ],
        "temperature": temperature,
        "stream": False
    }
    try:
        response = requests.post(OLLAMA_URL, json=payload, timeout=60).json()
        return response.get('message', {}).get('content', "").strip()
    except Exception as e:
        return ""

def generate_program(category: str, target_type: str, length: str, domain: str, previous_error: str = None) -> str:
    system_prompt = "You are an expert Python dataset engineer building structural datasets for termination analysis."
    
    length_instruction = ""
    if length == "short":
        length_instruction = "The code MUST be less than 15 logical lines. Keep the logic contained to a single function."
    elif length == "medium":
        length_instruction = "The code MUST be between 15 and 30 logical lines. Use at least two interacting functions."
    elif length == "long":
        length_instruction = "The code MUST be over 30 logical lines. Distribute the logic across at least three interacting functions or classes."

    user_prompt = f"""
    Write a Python script for the category: '{category}'.
    The program MUST be: {target_type.upper()}.
    The algorithmic domain/theme should be: {domain}.
    
    CRITICAL RULES:
    1. NO COMMENTS: Never use comments (`#`) or docstrings.
    2. LENGTH & STRUCTURE: {length_instruction}
    3. NEUTRAL NAMING: Variables must be generic. NEVER use words like `infinite`, `terminates`, `halt`, or `loop`.
    4. NO EXTERNAL CALLS: Do not use `time.sleep()`, `input()`, or external imports.
    5. EXECUTION: Call the main function at the bottom.
    6. Wrap the code in a ```python block.
    """
    
    if previous_error:
        user_prompt += f"\nWARNING: Previous attempt failed: {previous_error}. Fix the logic or structure."

    response = ask_llm(system_prompt, user_prompt, temperature=0.9)
    match = re.search(r"```python(.*?)```", response, re.DOTALL)
    return match.group(1).strip() if match else ""

def verify_infinite_loop(code_string: str, is_recursion=False) -> bool:
    system_prompt = "You are a formal verification system inspecting Python code."
    context = "crashed with a RecursionError" if is_recursion else "hit an execution timeout"
    user_prompt = f"The following program {context}. Determine if it is mathematically non-terminating.\nCode:\n```python\n{code_string}\n```\nAnswer ONLY with 'INFINITE' or 'SLOW'."
    return "INFINITE" in ask_llm(system_prompt, user_prompt, temperature=0.1).upper()

# ==========================================
# 4. THE EXECUTOR (SANDBOX)
# ==========================================
def run_untrusted_code(code_string, result_queue):
    import sys
    sys.setrecursionlimit(2000)
    try:
        exec(code_string, {"__builtins__": __builtins__})
        result_queue.put("SUCCESS")
    except RecursionError:
        result_queue.put("RECURSION_ERROR")
    except Exception as e:
        result_queue.put(f"ERROR_{type(e).__name__}")

def test_termination(code_string: str) -> tuple:
    queue = multiprocessing.Queue()
    process = multiprocessing.Process(target=run_untrusted_code, args=(code_string, queue))
    
    start_time = time.perf_counter()
    process.start()
    process.join(TIMEOUT_SECONDS)
    elapsed_ms = (time.perf_counter() - start_time) * 1000
    
    if process.is_alive():
        process.terminate()
        process.join()
        return "NON_TERMINATING", elapsed_ms
    
    if not queue.empty():
        status = queue.get()
        if status == "SUCCESS": return "TERMINATING", elapsed_ms
        elif status == "RECURSION_ERROR": return "NON_TERMINATING_RECURSION", elapsed_ms
        else: return "ERROR", elapsed_ms
    return "ERROR", elapsed_ms

# ==========================================
# 5. MAIN ORCHESTRATION LOOP
# ==========================================
def main():
    setup_directories()
    global_sample_id = 1
    seen_ast_hashes = set()
    
    print(f"\n🚀 Starting Scaled Halting Dataset Generation into flat folder: {DATASET_ROOT}\n")
    
    for category in CATEGORIES:
        for target in ["terminating", "non_terminating"]:
            for length in LENGTHS:
                successful_samples = 0
                
                while successful_samples < SAMPLES_PER_LENGTH:
                    domain = random.choice(DOMAINS)
                    print(f"  [ID: {global_sample_id:04d} | {category} | {target.upper()} | {length.upper()} | {successful_samples + 1}/{SAMPLES_PER_LENGTH}]")
                    
                    previous_error = None
                    raw_code = generate_program(category, target, length, domain, previous_error)
                    
                    if not raw_code:
                        print("    ❌ Failed to extract code. Retrying...")
                        continue
                    
                    is_structurally_valid, clean_code, line_count, validation_msg = validate_code_structure(raw_code, length)
                    if not is_structurally_valid:
                        print(f"    ❌ Structural Check Failed: {validation_msg}")
                        previous_error = validation_msg
                        continue
                        
                    ast_hash = get_ast_skeleton_hash(clean_code)
                    if ast_hash in seen_ast_hashes:
                        print("    ❌ AST Collision. Rejecting duplicate control flow.")
                        previous_error = "Write a completely different control flow structure."
                        continue

                    exec_result, exec_time_ms = test_termination(clean_code)
                    is_valid = False
                    
                    if exec_result == "ERROR":
                        print("    ❌ Code crashed. Discarding.")
                        previous_error = "The code threw an exception. Ensure it runs cleanly."
                    
                    elif target == "terminating":
                        if exec_result == "TERMINATING":
                            is_valid = True
                        elif exec_result == "NON_TERMINATING_RECURSION":
                            previous_error = "The program hit a RecursionError."
                        else:
                            previous_error = "The program timed out."

                    elif target == "non_terminating":
                        if exec_result == "NON_TERMINATING":
                            if verify_infinite_loop(clean_code, is_recursion=False): is_valid = True
                            else: previous_error = "Computationally slow, not infinite."
                        elif exec_result == "NON_TERMINATING_RECURSION":
                            if verify_infinite_loop(clean_code, is_recursion=True): is_valid = True
                            else: previous_error = "Too deep, not an unbound base case."
                        else:
                            previous_error = "The program halted. Write an infinite loop."

                    if is_valid:
                        seen_ast_hashes.add(ast_hash)
                        sample_name = f"sample_{global_sample_id:04d}"
                        
                        # Extract metrics for metadata
                        metrics = extract_metrics(clean_code)
                        
                        metadata = {
                            "id": sample_name,
                            "category": category,
                            "label": target,
                            "length": length,
                            "logical_loc": line_count,
                            "domain": domain,
                            "ast_nodes": metrics["ast_nodes"],
                            "cfg_nodes": metrics["cfg_nodes"],
                            "cyclomatic_complexity": metrics["cyclomatic_complexity"],
                            "loop_count": metrics["loop_count"],
                            "function_count": metrics["function_count"],
                            "execution_status": "SUCCESS" if target == "terminating" else "TIMEOUT/RECURSION",
                            "execution_time_ms": round(exec_time_ms, 2)
                        }

                        # Save Python File
                        py_path = os.path.join(DATASET_ROOT, f"{sample_name}.py")
                        with open(py_path, "w", encoding="utf-8") as f:
                            f.write(clean_code)
                            
                        # Save JSON Metadata File
                        json_path = os.path.join(DATASET_ROOT, f"{sample_name}.json")
                        with open(json_path, "w", encoding="utf-8") as f:
                            json.dump(metadata, f, indent=4)

                        print(f"    ✅ Saved {sample_name}.py & {sample_name}.json")
                        successful_samples += 1
                        global_sample_id += 1
                        
    print(f"\n🎉 Generation Complete! Files saved in './{DATASET_ROOT}'")

if __name__ == "__main__":
    multiprocessing.freeze_support() 
    main()