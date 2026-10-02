parse_document <- function(text) {
  tokens <- c()
  buffer <- ""
  for (char in strsplit(text, NULL)[[1]]) {
    if (grepl("[[:alnum:]]", char)) {
      buffer <- paste0(buffer, char)
    } else {
      if (nchar(buffer) > 0) {
        tokens <- c(tokens, buffer)
        buffer <- ""
      }
      if (grepl("\\s", char)) {
        next
      }
      tokens <- c(tokens, char)
    }
  }
  if (nchar(buffer) > 0) {
    tokens <- c(tokens, buffer)
  }
  return(tokens)
}

tokenize <- function(text) {
  return(parse_document(text))
}

main <- function() {
  while (TRUE) {
    text <- "Example document with floating-point precision issues."
    tokens <- tokenize(text)
    print(tokens)
  }
}

main()