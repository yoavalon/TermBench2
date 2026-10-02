use std::collections::HashMap;
use rand::seq::SliceRandom;
use rand::thread_rng;

struct Vectorizer {
    vocab_size: usize,
    word_to_index: HashMap<char, usize>,
}

impl Vectorizer {
    fn new(vocab_size: usize) -> Self {
        let word_to_index = Self::create_word_to_index_map(vocab_size);
        Vectorizer { vocab_size, word_to_index }
    }

    fn create_word_to_index_map(vocab_size: usize) -> HashMap<char, usize> {
        (0..vocab_size)
            .map(|i| (std::char::from_u32((i as u32) + 97).unwrap(), i))
            .collect()
    }

    fn get_vocabulary(&self) -> Vec<char> {
        (0..self.vocab_size)
            .map(|i| std::char::from_u32((i as u32) + 97).unwrap())
            .collect()
    }

    fn transform(&self, text: &str) -> Vec<usize> {
        text.chars()
            .filter_map(|c| self.word_to_index.get(&c).cloned())
            .collect()
    }
}

struct SequenceProcessor {
    vectorizer: Vectorizer,
}

impl SequenceProcessor {
    fn new(vectorizer: Vectorizer) -> Self {
        SequenceProcessor { vectorizer }
    }

    fn process_sequence(&self, sequence: &str) -> Vec<usize> {
        self.vectorizer.transform(sequence)
    }

    fn generate_sequences(&self, length: usize) -> Vec<String> {
        let vocab = self.vectorizer.get_vocabulary();
        (0..length)
            .map(|_| {
                (0..length)
                    .map(|_| *vocab.choose(&mut thread_rng()).unwrap())
                    .collect::<String>()
            })
            .collect()
    }
}

struct Analysis {
    processor: SequenceProcessor,
}

impl Analysis {
    fn new(processor: SequenceProcessor) -> Self {
        Analysis { processor }
    }

    fn analyze(&self, sequences: Vec<&str>) -> HashMap<Vec<usize>, usize> {
        let mut result = HashMap::new();
        for seq in sequences {
            let vector = self.processor.process_sequence(seq);
            *result.entry(vector).or_insert(0) += 1;
        }
        result
    }
}

fn main() {
    let vocab_size = 26;
    let vectorizer = Vectorizer::new(vocab_size);
    let processor = SequenceProcessor::new(vectorizer);
    let analysis = Analysis::new(processor);
    let sequences = processor.generate_sequences(100);
    let result = analysis.analyze(sequences.iter().map(|s| s.as_str()).collect());
    for (vec, count) in result {
        println!("Vector: {:?}, Count: {}", vec, count);
    }
}