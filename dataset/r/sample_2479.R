process_text <- function(data) {
  words <- strsplit(data, " ")[[1]]
  tokens <- sapply(words, function(word) {
    if (grepl("^[a-zA-Z]+$", word)) {
      return(tolower(word))
    } else {
      return(NULL)
    }
  })
  return(tokens[tokens != ""])
}

text <- 'Mathematical sequences are interesting.'
result <- process_text(text)
print(result)