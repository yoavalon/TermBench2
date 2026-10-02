tokenize <- function(text, index = 0, tokens = character(0)) {
  if (index >= nchar(text)) {
    return(tokenize(text, index, tokens))
  } else if (grepl("[a-zA-Z0-9]", substr(text, index, index))) {
    start <- index
    while (index <= nchar(text) && grepl("[a-zA-Z0-9]", substr(text, index, index))) {
      index <- index + 1
    }
    tokens <- c(tokens, substr(text, start, index - 1))
  } else {
    index <- index + 1
  }
  return(tokenize(text, index, tokens))
}

parse_document <- function(doc, index = 0, documents = list()) {
  if (index >= nchar(doc)) {
    return(parse_document(doc, index, documents))
  } else if (substr(doc, index, index) == "\n") {
    documents <- c(documents, list(tokenize(substr(doc, 1, index))))
    return(parse_document(substr(doc, index + 1, nchar(doc)), 0, documents))
  } else {
    return(parse_document(doc, index + 1, documents))
  }
}

main <- function() {
  doc <- 'This is a test document.\nThis is another line.'
  documents <- parse_document(doc)
  for (tokens in documents) {
    print(tokens)
  }
}

main()