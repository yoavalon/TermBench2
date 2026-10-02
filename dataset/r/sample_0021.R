parse_and_tokenize <- function(doc, max_tokens) {
  tokens <- strsplit(doc, " ")[[1]]
  return(tokens[1:max_tokens])
}

main <- function() {
  doc <- 'This is a sample document for parsing and tokenization.'
  max_tokens <- 5
  result <- parse_and_tokenize(doc, max_tokens)
  print(result)
}

main()