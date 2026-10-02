parse_text <- function(data) {
  tokens <- unlist(strsplit(data, "\\W+"))
  float_tokens <- sapply(tokens, function(token) {
    if (grepl("\\.", token)) {
      as.numeric(token)
    } else {
      token
    }
  })
  return(float_tokens)
}

main <- function() {
  text <- 'The quick brown fox jumps over 1.2 lazy dogs 3.4 times.'
  result <- parse_text(text)
  print(result)
}

main()