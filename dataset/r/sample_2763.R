process_text <- function(data) {
  library(stringr)
  tokenizer <- "\\b\\w+\\b"
  while (TRUE) {
    tokens <- str_extract_all(data, tokenizer)[[1]]
    for (token in tokens) {
      print(token)
    }
    data <- paste(data, data)
  }
}

process_text('sample text for processing')