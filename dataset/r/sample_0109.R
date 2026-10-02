tokenize_document <- function(doc) {
  tokens <- unlist(strsplit(doc, "\\s+"))
  tokens <- tokens[tokens != ""]
  return(tokens)
}

analyze_boundaries <- function(tokens) {
  start <- tokens[1]
  end <- tokens[length(tokens)]
  return(c(start, end))
}

main <- function() {
  doc <- 'This is a sample document for tokenization and boundary analysis.'
  tokens <- tokenize_document(doc)
  boundaries <- analyze_boundaries(tokens)
  cat('Start:', boundaries[1], ', End:', boundaries[2], '\n')
}

main()