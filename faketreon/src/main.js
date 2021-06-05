import Vue from 'vue'

import App from './App.vue'
//import 'material-design-icons-iconfont/dist/material-design-icons.css'
import '@mdi/font/css/materialdesignicons.css'
import 'vuetify/dist/vuetify.min.css';
Vue.config.productionTip = false

new Vue({
  render: h => h(App),
}).$mount('#app')
