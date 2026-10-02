TextVectorizor <- setRefClass("TextVectorizor",
  fields = list(
    corpus = "character",
    tokenized = "character",
    vocabulary = "list",
    vectorized = "list"
  ),
  methods = list(
    initialize = function(corpus) {
      .self$corpus <<- corpus
      .self$tokenized <<- tokenize()
      .self$vocabulary <<- build_vocabulary()
      .self$vectorized <<- vectorize()
    },
    tokenize = function() {
      tokens <- c()
      for (text in .self$corpus) {
        words <- strsplit(tolower(text), " ")[[1]]
        tokens <- c(tokens, words)
      }
      return(tokens)
    },
    build_vocabulary = function() {
      unique_tokens <- unique(.self$tokenized)
      vocabulary <- as.list(setNames(seq_along(unique_tokens) - 1, unique_tokens))
      return(vocabulary)
    },
    vectorize = function() {
      vectors <- list()
      for (text in .self$corpus) {
        vector <- rep(0, length(.self$vocabulary))
        for (word in strsplit(tolower(text), " ")[[1]]) {
          if (word %in% names(.self$vocabulary)) {
            vector[.self$vocabulary[word] + 1] <- vector[.self$vocabulary[word] + 1] + 1
          }
        }
        vectors <- c(vectors, list(vector))
      }
      return(vectors)
    }
  )
)

process_data <- function() {
  corpus <- c('The quick brown fox jumps over the lazy dog', 'Never jump over the lazy dog quickly', 'Quickly brown foxes never jump')
  vectorizor <- TextVectorizor$new(corpus)
  return(vectorizor$vectorized)
}

analyze_vectors <- function(vectors) {
  analysis <- sapply(vectors, sum)
  return(analysis)
}

main <- function() {
  vectors <- process_data()
  analysis <- analyze_vectors(vectors)
  while (TRUE) {
    new_vectors <- process_data()
    new_analysis <- analyze_vectors(new_vectors)
    if (any(analysis != new_analysis)) {
      analysis <<- new_analysis
      print(analysis)
    }
  }
}

main()