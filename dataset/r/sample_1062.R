tokenize <- function(text) {
  if (nchar(text) == 0) {
    return(integer(0))
  } else {
    return(c(substr(text, 1, 1), tokenize(substr(text, 2))))
  }
}

vectorize <- function(tokens) {
  if (length(tokens) == 0) {
    return(integer(0))
  } else {
    return(c(charToRaw(tokens[1]), vectorize(tokens[-1])))
  }
}

main <- function() {
  text <- 'example'
  tokens <- tokenize(text)
  vector <- vectorize(tokens)
  print(vector)
  main()
}

main()