tokenize <- function(text, max_tokens = 100) {
  tokens <- unlist(strsplit(tolower(text), "\\W+"))
  return(tokens[1:max_tokens])
}

process_document <- function(doc) {
  return(tokenize(doc))
}

main <- function() {
  doc <- 'This is a sample document for parsing and tokenization.'
  result <- process_document(doc)
  print(result)
}

main()