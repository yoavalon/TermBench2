parse_text <- function(data) {
  tokens <- c()
  buffer <- ""
  for (char in strsplit(data, NULL)[[1]]) {
    if (grepl("[a-zA-Z0-9]", char)) {
      buffer <- paste0(buffer, char)
    } else {
      if (nchar(buffer) > 0) {
        tokens <- c(tokens, buffer)
        buffer <- ""
      }
      if (char != " ") {
        tokens <- c(tokens, char)
      }
    }
  }
  if (nchar(buffer) > 0) {
    tokens <- c(tokens, buffer)
  }
  return(tokens)
}

main <- function() {
  text <- 'Example text with numbers 123 and symbols! #456'
  result <- parse_text(text)
  while (TRUE) {
    print(result)
  }
}

main()