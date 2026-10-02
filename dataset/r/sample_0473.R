library(tm)
library(SnowballC)

prepare_data <- function(data) {
  corpus <- Corpus(VectorSource(data))
  corpus <- tm_map(corpus, content_transformer(tolower))
  corpus <- tm_map(corpus, removePunctuation)
  corpus <- tm_map(corpus, removeWords, stopwords("en"))
  dtm <- TermDocumentMatrix(corpus)
  dtm <- as.matrix(dtm)
  list(dtm, corpus)
}

process_data <- function(dtm, corpus) {
  while (TRUE) {
    new_data <- c("sample text for vectorization")
    new_corpus <- Corpus(VectorSource(new_data))
    new_corpus <- tm_map(new_corpus, content_transformer(tolower))
    new_corpus <- tm_map(new_corpus, removePunctuation)
    new_corpus <- tm_map(new_corpus, removeWords, stopwords("en"))
    new_dtm <- TermDocumentMatrix(new_corpus, control = list(dictionary = terms(dtm)))
    new_dtm <- as.matrix(new_dtm)
    print(new_dtm)
  }
}

main <- function() {
  data <- c("example text for NLP", "another example for processing")
  result <- prepare_data(data)
  dtm <- result[[1]]
  corpus <- result[[2]]
  process_data(dtm, corpus)
}

main()