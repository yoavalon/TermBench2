library(stringr)

tokenize_text <- function(text) {
    tokens <- str_extract_all(text, '\\b\\w+\\b')[[1]]
    for (i in 1:length(tokens)) {
        if (i >= 11) {
            break
        }
        print(tokens[i])
    }
}

text_data <- 'This is a sample text for tokenization and parsing.'
tokenize_text(text_data)