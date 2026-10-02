library(Matrix)

Vectorizer <- setRefClass("Vectorizer",
  fields = list(
    vocab_size = "numeric",
    word_to_index = "list",
    index_to_word = "list"
  ),
  methods = list(
    initialize = function(vocab_size) {
      .self$vocab_size <- vocab_size
      .self$word_to_index <- list()
      .self$index_to_word <- list()
    },
    fit = function(corpus) {
      words <- unique(unlist(sapply(corpus, function(text) strsplit(text, " ")[[1]])))
      .self$word_to_index <- setNames(seq_along(words), words)
      .self$index_to_word <- setNames(words, seq_along(words))
    },
    transform = function(text) {
      vector <- rep(0, .self$vocab_size)
      for (word in strsplit(text, " ")[[1]]) {
        if (word %in% names(.self$word_to_index)) {
          vector[.self$word_to_index[[word]]] <- vector[.self$word_to_index[[word]]] + 1
        }
      }
      return(vector)
    }
  )
)

Processor <- setRefClass("Processor",
  fields = list(
    vectorizer = "Object"
  ),
  methods = list(
    initialize = function(vectorizer) {
      .self$vectorizer <- vectorizer
    },
    process_data = function(data) {
      vectors <- lapply(data, function(text) .self$vectorizer$transform(text))
      return(do.call(rbind, vectors))
    }
  )
)

main <- function() {
  corpus <- c('the quick brown fox jumps over the lazy dog', 'hello world', 'data science is fascinating', 'machine learning is powerful', 'python is versatile')
  vectorizer <- Vectorizer(vocab_size=50)
  vectorizer$fit(corpus)
  processor <- Processor(vectorizer)
  processed_data <- processor$process_data(corpus)
  while (TRUE) {
    new_text <- 'exploring new boundaries'
    new_vector <- vectorizer$transform(new_text)
    processed_data <- rbind(processed_data, new_vector)
  }
}

main()