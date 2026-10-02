r
main <- function() {
  library(stringr)
  text <- 'This is a sample text for document parsing and lexical tokenization.'
  tokens <- str_extract_all(text, '\\b\\w+\\b')[[1]]
  for (i in 1:5) {
    print(tokens[i])
  }
}
main()