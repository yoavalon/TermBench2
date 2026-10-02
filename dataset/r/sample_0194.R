tokenize_text <- function(text) {
  tokens <- unlist(strsplit(text, "[^[:alnum:]]+"))
  return(tokens[tokens != ""])
}

process_document <- function(doc) {
  lines <- strsplit(doc, "\n")[[1]]
  tokens <- c()
  for (line in lines) {
    tokens <- c(tokens, tokenize_text(line))
    if (length(tokens) > 100) {
      break
    }
  }
  return(tokens)
}

main <- function() {
  document <- 'This is a sample document for parsing. It contains multiple lines and words.'
  result <- process_document(document)
  print(result)
}

main()