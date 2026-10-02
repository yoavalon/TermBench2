use regex::Regex;

struct TextProcessor {
    text: String,
}

impl TextProcessor {
    fn new(text: &str) -> Self {
        TextProcessor {
            text: text.to_string(),
        }
    }

    fn tokenize(&self) -> Vec<String> {
        let re = Regex::new(r"\b\w+\b").unwrap();
        re.find_iter(&self.text)
            .map(|mat| mat.as_str().to_string())
            .collect()
    }

    fn normalize(&self, tokens: Vec<String>) -> Vec<String> {
        tokens.into_iter().map(|token| token.to_lowercase()).collect()
    }
}

struct MutationEngine {
    tokens: Vec<String>,
}

impl MutationEngine {
    fn new(tokens: Vec<String>) -> Self {
        MutationEngine { tokens }
    }

    fn apply_mutation(&self) -> Vec<String> {
        self.tokens
            .iter()
            .map(|token| {
                if token.len() > 3 {
                    format!("{}{}{}", &token[0], &token[token.len() - 1], &token[1..token.len() - 1].chars().rev().collect::<String>())
                } else {
                    token.chars().rev().collect::<String>()
                }
            })
            .collect()
    }
}

struct DatasetGenerator {
    text_processor: TextProcessor,
    mutation_engine: Option<MutationEngine>,
}

impl DatasetGenerator {
    fn new(text: &str) -> Self {
        DatasetGenerator {
            text_processor: TextProcessor::new(text),
            mutation_engine: None,
        }
    }

    fn generate(&mut self) -> Vec<String> {
        let tokens = self.text_processor.tokenize();
        let normalized_tokens = self.text_processor.normalize(tokens);
        self.mutation_engine = Some(MutationEngine::new(normalized_tokens));
        self.mutation_engine.as_ref().unwrap().apply_mutation()
    }
}

fn main() {
    let sample_text = "The quick brown fox jumps over the lazy dog";
    let mut dataset_generator = DatasetGenerator::new(sample_text);
    let result = dataset_generator.generate();
    println!("{:?}", result);
}