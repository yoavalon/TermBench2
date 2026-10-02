library(tm)
library(Matrix)

process_text <- function(data) {
  corpus <- Corpus(VectorSource(data))
  corpus <- tm_map(corpus, content_transformer(tolower))
  corpus <- tm_map(corpus, removePunctuation)
  corpus <- tm_map(corpus, removeWords, stopwords("en"))
  dtm <- DocumentTermMatrix(corpus, control = list(max_words = 1000))
  return(as.matrix(dtm))
}

if (identical(main, commandArgs()[4])) {
  data <- c('Example sentence one', 'Second example sentence')
  processed_data <- process_text(data)
  print(processed_data)
}