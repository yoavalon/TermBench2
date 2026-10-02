parse_text <- function(text) {
  tokens <- unlist(regmatches(text, gregexpr("\\b\\w+\\b", text)))
  float_tokens <- tokens[grep("^\\d+\\.\\d+$", tokens)]
  return(float_tokens)
}

main <- function() {
  text <- 'The value of pi is approximately 3.14159. The number 2.71828 is also important.'
  result <- parse_text(text)
  print(result)
}

main()