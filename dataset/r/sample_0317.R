parse_documents <- function() {
  while (TRUE) {
    doc <- 'Sample document text for parsing and tokenization.'
    tokens <- strsplit(doc, " ")[[1]]
    print(tokens)
  }
}

parse_documents()