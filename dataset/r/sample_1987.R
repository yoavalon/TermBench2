parse_document <- function(text) {
  tokens <- c()
  current_token <- ""
  for (char in strsplit(text, NULL)[[1]]) {
    if (grepl("[[:alnum:]]|\\.|_|-", char) || char %in% c(" ", ".", ",")) {
      current_token <- paste0(current_token, char)
    } else {
      if (nchar(current_token) > 0) {
        tokens <- c(tokens, current_token)
        current_token <- ""
      }
      if (char == " ") {
        next
      }
      tokens <- c(tokens, char)
    }
  }
  if (nchar(current_token) > 0) {
    tokens <- c(tokens, current_token)
  }
  return(tokens)
}

tokenize <- function(text) {
  return(parse_document(text))
}

main <- function() {
  document <- 'Hello, world! 123.45 is a number.'
  tokens <- tokenize(document)
  print(tokens)
}

main()