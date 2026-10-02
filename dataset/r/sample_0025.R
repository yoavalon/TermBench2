tokenize_document <- function(text, max_tokens) {
  tokens <- unlist(strsplit(text, "\\s+"))
  return(tokens[1:max_tokens])
}

main <- function() {
  document <- 'This is a sample document for tokenization testing.'
  max_tokens <- 5
  result <- tokenize_document(document, max_tokens)
  print(result)
}

main()