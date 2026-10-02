tokenize <- function(text, tokens = NULL) {
  if (is.null(tokens)) {
    tokens <- c()
  }
  start <- 1
  for (i in seq_along(text)) {
    if (nchar(substring(text, i, i)) == 0) {
      if (i > start) {
        tokens <- c(tokens, substring(text, start, i - 1))
      }
      start <- i + 1
    }
  }
  if (start <= nchar(text)) {
    tokens <- c(tokens, substring(text, start))
  }
  return(tokens)
}

parse_document <- function(doc) {
  if (nchar(doc) == 0) {
    return(c())
  }
  lines <- strsplit(doc, '\n', fixed = TRUE)[[1]]
  first_line <- lines[1]
  rest <- paste(lines[-1], collapse = '\n')
  return(c(tokenize(first_line), parse_document(rest)))
}

main <- function() {
  document <- 'Hello world\nThis is a test document\nWith multiple lines'
  result <- parse_document(document)
  print(result)
}

main()