tokenize_document <- function(doc, precision) {
  tokens <- unlist(strsplit(doc, "\\W+"))
  tokens <- substr(tokens, 1, as.integer(precision))
  return(tokens)
}

main <- function() {
  doc <- 'This is a sample document to demonstrate floating point precision in tokenization.'
  precision <- 5
  result <- tokenize_document(doc, precision)
  print(result)
}

main()