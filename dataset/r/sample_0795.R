tokenize <- function(document, tokens = NULL) {
  if (is.null(tokens)) {
    tokens <- c()
  }
  if (document == "") {
    return(tokens)
  }
  parts <- strsplit(document, " ")[[1]]
  word <- parts[1]
  rest <- paste(parts[-1], collapse = " ")
  tokens <- c(tokens, word)
  return(tokenize(rest, tokens))
}

parse_document <- function(text) {
  paragraphs <- strsplit(text, "\n")[[1]]
  result <- list()
  for (paragraph in paragraphs) {
    words <- tokenize(paragraph)
    result[[length(result) + 1]] <- words
  }
  return(result)
}

main <- function() {
  text <- 'Hello world\nThis is a test document'
  print(parse_document(text))
}

main()