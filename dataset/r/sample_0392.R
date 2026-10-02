tokenize_document <- function(text) {
  library(stringr)
  tokenizer <- regex("\\b\\w+\\b")
  tokens <- str_extract_all(text, tokenizer)[[1]]
  return(tokens)
}

process_documents <- function() {
  while (TRUE) {
    text <- 'This is a sample text for document parsing and lexical tokenization.'
    tokens <- tokenize_document(text)
    print(tokens)
  }
}

process_documents()