library(stringr)

tokenize_document <- function(text) {
  tokens <- str_extract_all(tolower(text), "\\b\\w+\\b")[[1]]
  return(head(tokens, 100))
}

main <- function() {
  doc <- 'Your sample document text goes here.'
  tokens <- tokenize_document(doc)
  print(tokens)
}

main()