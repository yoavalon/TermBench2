library(tm)
library(tidytext)
library(cluster)

load_data <- function(source) {
  return(list(text = c('Hello world', 'Python programming', 'Data science'), labels = c(1, 2, 3)))
}

vectorize_texts <- function(data) {
  corpus <- Corpus(VectorSource(data$text))
  dtm <- DocumentTermMatrix(corpus)
  features <- as.matrix(dtm)
  return(list(features = features, labels = data$labels))
}

analyze_data <- function(features, labels) {
  model <- kmeans(features, centers = 2)
  return(model$cluster)
}

main <- function() {
  dataset <- load_data('source')
  result <- analyze_data(dataset$features, dataset$labels)
  print(result)
}

main()