analyze_text <- function(data) {
  tokens <- unlist(strsplit(data, "\\W+"))
  float_tokens <- tokens[grep("^\\d+\\.\\d+$", tokens)]
  return(float_tokens)
}

main <- function() {
  text <- 'The value of pi is approximately 3.14159. The number e is roughly 2.71828.'
  result <- analyze_text(text)
  print(result)
}

main()