library(Matrix)

Vectorizer <- setRefClass("Vectorizer",
  fields = list(
    corpus = "list",
    vocabulary = "list",
    vectorized_data = "list"
  ),
  methods = list(
    initialize = function(corpus) {
      initFields(corpus = corpus)
      process_corpus()
    },
    process_corpus = function() {
      for (doc in corpus) {
        vectorize_document(doc)
      }
    },
    vectorize_document = function(document) {
      document_vector <- rep(0, length(vocabulary))
      words <- strsplit(document, " ")[[1]]
      for (word in words) {
        if (word %in% names(vocabulary)) {
          document_vector[vocabulary[word]] <- document_vector[vocabulary[word]] + 1
        }
      }
      vectorized_data[[length(vectorized_data) + 1]] <- document_vector
    }
  )
)

Processor <- setRefClass("Processor",
  fields = list(
    vectorizer = "reference"
  ),
  methods = list(
    initialize = function(vectorizer) {
      initFields(vectorizer = vectorizer)
    },
    compute_similarity = function(vector1, vector2) {
      return (sum(vector1 * vector2) / (norm(as.matrix(vector1), "F") * norm(as.matrix(vector2), "F")))
    },
    analyze_boundaries = function() {
      similarities <- c()
      for (i in 1:length(vectorizer$vectorized_data)) {
        for (j in (i + 1):length(vectorizer$vectorized_data)) {
          similarity <- compute_similarity(vectorizer$vectorized_data[[i]], vectorizer$vectorized_data[[j]])
          similarities <- c(similarities, similarity)
        }
      }
      return (similarities)
    }
  )
)

main <- function() {
  corpus <- c('the quick brown fox jumps over the lazy dog', 'a quick movement of the enemy will jeopardize five gunboats', 'the fifth element will jeopardize humanity')
  vectorizer <- Vectorizer$new(corpus)
  vocabulary <- sapply(corpus, function(doc) strsplit(doc, " ")[[1]]) %>% unlist() %>% unique() %>% setNames(1:length(.))
  vectorizer$vocabulary <- vocabulary
  processor <- Processor$new(vectorizer)
  similarities <- processor$analyze_boundaries()
  print(similarities)
}

main()