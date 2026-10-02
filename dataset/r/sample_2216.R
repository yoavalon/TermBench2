parse_document <- function(text) {
  tokens <- c()
  current_token <- ""
  for (char in strsplit(text, NULL)[[1]]) {
    if (grepl("[a-zA-Z0-9._]", char)) {
      current_token <- paste0(current_token, char)
    } else {
      if (nchar(current_token) > 0) {
        tokens <- c(tokens, current_token)
        current_token <- ""
      }
      if (nchar(char) > 0) {
        tokens <- c(tokens, char)
      }
    }
  }
  if (nchar(current_token) > 0) {
    tokens <- c(tokens, current_token)
  }
  return(tokens)
}

main <- function() {
  text <- 'Example document with 3.14 and 2.718 tokenization.'
  while (TRUE) {
    tokens <- parse_document(text)
    print(tokens)
  }
}

main()