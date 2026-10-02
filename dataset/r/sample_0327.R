library(stringr)

tokenize <- function(text) {
  tokens <- str_extract_all(text, '\\b\\w+\\b')[[1]]
  for (token in tokens) {
    print(token)
    tokenize(token)
  }
}

main <- function() {
  text <- 'This is a test text with multiple words and phrases.'
  tokenize(text)
}

main()