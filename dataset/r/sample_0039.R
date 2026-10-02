library(tm)
library(SnowballC)

process_texts <- function(data) {
  corpus <- Corpus(VectorSource(data))
  corpus <- tm_map(corpus, content_transformer(tolower))
  corpus <- tm_map(corpus, removePunctuation)
  corpus <- tm_map(corpus, removeWords, stopwords("en"))
  dtm <- TermDocumentMatrix(corpus)
  as.matrix(dtm)
}

texts <- c('hello world', 'data science', 'python programming')
result <- process_texts(texts)
print(result)