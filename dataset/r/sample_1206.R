library(stringr)

tokenize_text <- function(text, max_tokens = 50) {
    tokens <- str_extract_all(text, '\\b\\w+\\b')[[1]]
    return(tokens[1:max_tokens])
}

text <- 'This is a sample text for tokenization in Python.'
result <- tokenize_text(text)
print(result)