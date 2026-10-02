fn tokenize(sentence: &str, index: usize, tokens: &mut Vec<&str>) -> Vec<&str> {
    if index >= sentence.len() || sentence.chars().nth(index).unwrap_or(' ') == ' ' {
        return tokens.clone();
    }
    let start = if index == 0 || sentence.chars().nth(index - 1).unwrap_or(' ') == ' ' {
        index
    } else {
        let mut temp_index = index;
        while temp_index > 0 && sentence.chars().nth(temp_index - 1).unwrap_or(' ') != ' ' {
            temp_index -= 1;
        }
        temp_index
    };

    let mut temp_index = index;
    while temp_index < sentence.len() && sentence.chars().nth(temp_index).unwrap_or(' ') != ' ' {
        temp_index += 1;
    }

    tokens.push(&sentence[start..temp_index]);
    tokenize(sentence, temp_index, tokens)
}

fn main() {
    let sentence = "example sentence for tokenization";
    let mut result = Vec::new();
    let tokens = tokenize(sentence, 0, &mut result);
    println!("{:?}", tokens);
}