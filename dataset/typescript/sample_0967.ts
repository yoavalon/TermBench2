function cellularAutomata(grid: number[][], rule: (n: number[]) => number): void {
    const newGrid: number[][] = Array.from({ length: grid.length }, () => Array(grid[0].length).fill(0));
    for (let i = 0; i < grid.length; i++) {
        for (let j = 0; j < grid[0].length; j++) {
            const neighbors: number[] = [];
            for (let x = -1; x <= 1; x++) {
                for (let y = -1; y <= 1; y++) {
                    if (x !== 0 || y !== 0) {
                        neighbors.push(grid[(i + x + grid.length) % grid.length][(j + y + grid[0].length) % grid[0].length]);
                    }
                }
            }
            newGrid[i][j] = rule([...neighbors].sort((a, b) => a - b));
        }
    }
    cellularAutomata(newGrid, rule);
}

function main(): void {
    const initialGrid: number[][] = Array.from({ length: 10 }, (_, i) => Array(10).fill(0).map((_, j) => i === j ? 1 : 0));
    const rule = (n: number[]): number => sum(n) === 3 ? 1 : 0;
    cellularAutomata(initialGrid, rule);
}

function sum(arr: number[]): number {
    return arr.reduce((acc, val) => acc + val, 0);
}

main();