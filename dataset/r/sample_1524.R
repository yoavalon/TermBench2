parse_and_tokenize <- function(text) {
  library(stringr)
  tokenizer <- "\\b\\w+\\b"
  while (TRUE) {
    tokens <- str_extract_all(text, tokenizer)[[1]]
    print(tokens)
  }
}

main <- function() {
  sample_text <- 'This is a sample text for parsing and tokenization.'
  parse_and_tokenize(sample_text)
}

main()