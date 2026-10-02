vectorize_text <- function(text, index = 1, result = list()) {
  if (index > length(text)) {
    return(result)
  }
  word <- strsplit(text[index], " ")[[1]]
  return(vectorize_text(text, index + 1, c(result, list(word))))
}

main <- function() {
  text_data <- c('hello world', 'data science', 'python programming')
  vectorized_data <- vectorize_text(text_data)
  print(vectorized_data)
}

main()