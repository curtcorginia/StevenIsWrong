/*
var app = new Vue({ 
    el: '#app',
    data: {
        message: 'Hello Vue!'
    }
});
*/
/*
Nutrition Calculator
React Functions:
- AddItem
- NutritionItem
- App
*/

var myapp = new Vue({
  el: '#app',
  data: {
    newDescription: '',
    newCalories: '',
    newFat: '',
    newCarbs: '',
    newProtein: '',
    totalCalories: '',
    totalFat: '',
    totalCarbs: '',
    totalProtein: '',
    entries: [
      { id: 3, description:'This is an item', calories: 223, fat: 12, carbs: 30, protein: 10 },
      { id: 2, description:'This is also an item', calories: 50, fat: 1, carbs: 10, protein: 1 },
      { id: 1, description:'Hey, me, too!', calories: 175, fat: 3, carbs: 15, protein: 8 }
    ]
  },
  methods: {
    addEntry: function () {
      var description = this.newDescription.trim()
      var calories = parseInt(this.newCalories.trim()) || 0
      var fat = parseInt(this.newFat.trim()) || 0
      var carbs = parseInt(this.newCarbs.trim()) || 0
      var protein = parseInt(this.newProtein.trim()) || 0
      if (description && calories) {
        this.entries.push({ description: description, calories: calories, fat: fat, carbs: carbs, protein: protein })
        this.newDescription = ''
        this.newCalories = ''
        this.newFat = ''
        this.newCarbs = ''
        this.newProtein = ''
        calculateTotals(this)
      } else {
        alert("You need at least a description and calories!")
      }
    },
    removeEntry: function (index) {
      this.entries.splice(index, 1)
      calculateTotals(this)
    },
    saveEntry: function() {
      calculateTotals(this)
    }
  }
})

function calculateTotals(app) {
  app.totalCalories = parseTotals(app.entries, 'calories')
  app.totalFat = parseTotals(app.entries, 'fat')
  app.totalCarbs = parseTotals(app.entries, 'carbs')
  app.totalProtein = parseTotals(app.entries, 'protein')
}

calculateTotals(myapp)

function parseTotals(array, element) {
  var sum = 0
  array.forEach(function(entry) {
    sum = sum + parseInt(entry[element])
  }, sum, element)
  return sum
}