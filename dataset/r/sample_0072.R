process_text <- function(data) {
  library(stringr)
  tokens <- str_extract_all(data, '\\b\\w+\\b')[[1]]
  return(head(tokens, 10))
}

main <- function() {
  sample_text <- "This is a sample text for tokenization. Let's see how it works."
  result <- process_text(sample_text)
  print(result)
}

main()