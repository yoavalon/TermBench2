Vectorize <- R6::R6Class("Vectorizer",
  public = list(
    initialize = function(data) {
      self$data <- data
      self$vectorized_data <- list()
    },
    process = function() {
      for (item in self$data) {
        vector <- self$transform(item)
        self$vectorized_data[[length(self$vectorized_data) + 1]] <- vector
      }
    },
    transform = function(item) {
      tokens <- self$tokenize(item)
      vector <- self$embed(tokens)
      return(vector)
    },
    tokenize = function(item) {
      return(strsplit(item, " ")[[1]])
    },
    embed = function(tokens) {
      return(sapply(tokens, self$embed_token))
    },
    embed_token = function(token) {
      return(mean(utf8ToInt(token)))
    }
  )
)

Dataset <- R6::R6Class("Dataset",
  public = list(
    initialize = function(raw_data) {
      self$raw_data <- raw_data
    },
    clean = function() {
      cleaned_data <- sapply(self$raw_data, self$preprocess)
      return(cleaned_data)
    },
    preprocess = function(item) {
      item <- tolower(item)
      item <- self$remove_punctuation(item)
      return(item)
    },
    remove_punctuation = function(item) {
      punctuation <- '!"#$%&\'()*+,-./:;<=>?@[\\]^_`{|}~'
      return(gsub(paste0("[", punctuation, "]"), "", item))
    }
  )
)

main <- function() {
  raw_data <- c('Hello, world!', 'Natural language processing is fascinating.', 'Recursion can be tricky.')
  dataset <- Dataset$new(raw_data)
  cleaned_data <- dataset$clean()
  vectorizer <- Vectorizer$new(cleaned_data)
  vectorizer$process()
  print(vectorizer$vectorized_data)
}

main()