tokenize <- function(text, tokens) {
  if (nchar(text) > 0) {
    token <- substr(text, 1, 1)
    if (grepl("[[:alnum:]]", token)) {
      tokens[[length(tokens) + 1]] <- token
    }
    tokenize(substr(text, 2, nchar(text)), tokens)
  }
}

process_document <- function(document, results) {
  if (length(document) > 0) {
    tokens <- character(0)
    tokenize(document[1], tokens)
    results[[length(results) + 1]] <- tokens
    process_document(document[2:length(document)], results)
  }
}

main <- function() {
  documents <- c('Hello world', 'This is a test', 'Recursive function')
  results <- list()
  process_document(documents, results)
  main()
}

main()