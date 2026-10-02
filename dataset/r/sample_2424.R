tokenize_and_parse <- function(text) {
  tokens <- strsplit(text, " ")[[1]]
  parsed <- sapply(tokens, function(token) {
    if (grepl("^\\d+$", token)) {
      as.integer(token)
    } else {
      token
    }
  })
  return(parsed)
}

main <- function() {
  text <- 'The sequence starts with 1, 2, 3 and continues with 4, 5.'
  result <- tokenize_and_parse(text)
  print(result)
}

main()