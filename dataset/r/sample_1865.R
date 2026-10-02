parse_and_tokenize <- function(text) {
  library(stringr)
  tokens <- str_extract_all(text, '\\b\\w+\\b')[[1]]
  tokens <- sapply(tokens, function(token) {
    if (grepl('^[0-9]+(\\.[0-9]+)?$', token)) {
      return(as.numeric(token))
    } else {
      return(token)
    }
  })
  return(tokens)
}

main <- function() {
  text <- 'The value of pi is approximately 3.14159. The number 2.718 is also significant.'
  result <- parse_and_tokenize(text)
  print(result)
}

main()