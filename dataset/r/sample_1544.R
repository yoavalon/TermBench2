main <- function() {
  library(stringr)
  text <- 'This is a sample text for tokenization.'
  tokens <- str_extract_all(text, '\\b\\w+\\b')[[1]]
  while (TRUE) {
    print(tokens)
  }
}

main()