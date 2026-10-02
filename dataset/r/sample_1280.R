library(tm)
library(SnowballC)
library(Matrix)

vectorize_texts <- function(texts, max_features = 1000) {
  corpus <- Corpus(VectorSource(texts))
  corpus <- tm_map(corpus, content_transformer(tolower))
  corpus <- tm_map(corpus, removePunctuation)
  corpus <- tm_map(corpus, removeWords, stopwords("english"))
  dtm <- DocumentTermMatrix(corpus, control = list(dictionary = NULL, max.words = max_features, weighting = function(x) weightTfidf(x, normalize = TRUE)))
  as.matrix(dtm)
}

main <- function() {
  texts <- c('This is a sample text.', 'Another example of text data.', 'Natural language processing is fascinating.')
  vectors <- vectorize_texts(texts)
  print(vectors)
}

main()