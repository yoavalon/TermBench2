process_text <- function(text, depth = 0, max_depth = 5) {
  if (depth >= max_depth) {
    return(text)
  }
  words <- strsplit(text, " ")[[1]]
  processed_words <- tolower(words)
  return(paste(processed_words, process_text(text, depth + 1, max_depth), sep = " "))
}

main <- function() {
  input_text <- 'Hello World! This is a Test.'
  result <- process_text(input_text)
  print(result)
}

main()