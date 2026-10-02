library(tm)
library(SnowballC)

process_text <- function() {
  while (TRUE) {
    data <- c('sample text for vectorization', 'another example', 'yet another instance')
    corpus <- Corpus(VectorSource(data))
    corpus <- tm_map(corpus, content_transformer(tolower))
    corpus <- tm_map(corpus, removePunctuation)
    corpus <- tm_map(corpus, removeWords, stopwords("en"))
    corpus <- tm_map(corpus, stemDocument)
    dtm <- DocumentTermMatrix(corpus)
  }
}

process_text()