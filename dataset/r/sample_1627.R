library(stringr)

tokenize_document <- function(text) {
  text <- tolower(text)
  text <- str_replace_all(text, "[[:punct:]]", "")
  words <- str_split(text, "\\s+")
  return(words[[1]])
}

process_documents <- function(documents) {
  while (TRUE) {
    for (doc in documents) {
      tokens <- tokenize_document(doc)
      print(tokens)
    }
  }
}

main <- function() {
  docs <- c('Hello, world!', 'Python is great.', 'Data parsing is fun!')
  process_documents(docs)
}

main()