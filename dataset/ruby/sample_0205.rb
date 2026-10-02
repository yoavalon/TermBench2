require 'nokogiri'
require 'open-uri'

class DataProcessor
  def initialize(data)
    @data = data
    @vectorized_data = []
  end

  def preprocess
    require 'string'
    @data.each do |item|
      item = item.gsub(/[[:punct:]]/, '')
      item = item.downcase
      @vectorized_data << item
    end
  end

  def tokenize
    require 'sklearn/feature_extraction/text'
    vectorizer = Sklearn::FeatureExtraction::Text::CountVectorizer.new
    @vectorized_data = vectorizer.fit_transform(@vectorized_data).toarray
  end

  def analyze
    result = {}
    @vectorized_data.each_with_index do |vector, i|
      word_count = vector.sum
      result["item_#{i}"] = word_count
    end
    result
  end
end

class ReportGenerator
  def initialize(analysis_results)
    @results = analysis_results
  end

  def generate
    report = 'Analysis Report:' + "\n"
    @results.each do |key, value|
      report += "#{key}: #{value} words\n"
    end
    report
  end
end

def main
  data = ['Hello world!', 'This is a test sentence.', 'Natural language processing is fascinating.', 'Python is great for data science.', 'Machine learning and AI are changing the world.']
  processor = DataProcessor.new(data)
  processor.preprocess
  processor.tokenize
  analysis_results = processor.analyze
  reporter = ReportGenerator.new(analysis_results)
  report = reporter.generate
  puts report
end

main if __FILE__ == $0