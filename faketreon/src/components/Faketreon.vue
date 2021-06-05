<template>

  
  <div class="faketreon">
    
    <v-app-bar
      color="white"
      dense
      light
    >
      <v-btn icon href="https://twitter.com/hashtag/faketreon?src=hash">
        <v-icon>mdi-alpha-f-circle</v-icon>
      </v-btn>
      <v-spacer></v-spacer>
      <v-btn icon>
        <v-icon>mdi-magnify</v-icon>
      </v-btn>
      <v-form>
        <v-container>
            <v-row>
              <v-col cols="12" sm="12">
                    <v-text-field
                >Search for a user</v-text-field>
              </v-col>
            </v-row>
        </v-container>
      </v-form>  
      <v-btn text small>Create on Patreon</v-btn>
      <v-btn text small>Log in</v-btn>
    </v-app-bar>
    <v-container fluid>
      <v-row justify="space-around">
        <v-col cols="12">
          <v-img :src="images.computer" aspect-ratio="2.9"></v-img>
          <v-card flat tile class="d-flex">
            <v-row justify="space-around">                
            </v-row>
          </v-card>
        </v-col>
        </v-row>
    </v-container>
        <v-row justify="space-around">
          <v-col cols="12">
            <v-avatar color="indigo" size="100">
              <span class="white--text headline"><v-img src="images.computer" position='center'></v-img></span>
                  <div class="fill-height bottom-gradient"></div>
                
            </v-avatar>
          </v-col>
        </v-row>
        <v-row>
          <v-col cols="12">
            <center><b>Evan</b></center>
            <center>is creating blog posts, long Facebook statuses, and fake Patreon pages</center>
            <br>
            <br>
            <h3>Select a membership level</h3>
            <center></center>
          </v-col>
        </v-row>
      <v-container class="grey lighten-5">
        <v-row no-gutters>
          <v-col order="last">
            <v-card
              class="pa-2"
              outlined
              tile
            >
              <h4>Thank you for your support!</h4>
              <br>
              <br>
              <h1>
                $1 per post 
              </h1>
              <br>   
              <div class="text-center">
                <v-btn
                  rounded
                  color="primary"
                  dark
                  @click="snackbarOne = true"
                >
                  Donate
                </v-btn>
                <v-snackbar
                  v-model="snackbarOne"
                  :multi-line="multiLine"
                >
                  {{ calmText }}
                  <v-btn
                    color="green"
                    text
                    @click="snackbarOne = false"
                  >
                    Close
                  </v-btn>
                  
                </v-snackbar>
                
                <v-card-title primary-title class="justify-left" >
                  <ul>
                    <li>No benefits</li>                   
                  </ul>   
                </v-card-title>     
              </div>
            </v-card>
          </v-col>
          <v-col>
            <v-card
              class="pa-2"
              outlined
              tile
            >
              <h4>Thank you for even more support!</h4>
              <br>
              <br>
              <h1>
                $5 per post 
              </h1>
              <br>
              <div class="text-center">
                <v-btn
                  rounded
                  color="primary"
                  dark
                  @click="snackbarTwo = true"
                >
                  Donate
                </v-btn>
                <v-snackbar
                  v-model="snackbarTwo"
                  :multi-line="multiLine"
                >
                  {{ weirdText }}
                  <v-btn
                    color="orange"
                    text
                    @click="snackbarTwo = false"
                  >
                    Close
                  </v-btn>
                </v-snackbar>
                <v-card-title primary-title class="justify-left" >
                  <ul>
                    <li>Still no benefits</li>       
                  </ul>   
                </v-card-title>
              </div>
            </v-card>
          </v-col>
          <v-col order="first">
            <v-card
              class="pa-2"
              outlined
              tile
            >
              <h4>That's way too much what are you doing</h4>
              <br>
              <br>
              <h1>
                $20 per post 
              </h1>
              <br>
              <div class="text-center">
                <v-btn
                  rounded
                  color="primary"
                  dark
                  @click="snackbarThree = true"
                >
                  Donate
                </v-btn>
                <v-snackbar
                  v-model="snackbarThree"
                  :multi-line="multiLine"
                >
                  {{ angryText }}
                  <v-btn
                    color="red"
                    text
                    @click="snackbarThree = false"
                  >
                    Close
                  </v-btn>
                </v-snackbar>
                  <v-card-title primary-title class="justify-left" >
                  <ul>
                    <li>Even this gets you no benefits</li>
                  </ul>   
                </v-card-title>
              </div>
            </v-card>
          </v-col>
        </v-row>
          <v-col> 
            <p><b>0</b></p>
            <p><b>Patrons</b></p>
          </v-col>
          <v-col> 
            <p><b>$0</b></p>
            <p><b>per blog post</b></p>
            <br>
            <h1>About</h1>
            <h3>Do you like reading the writing I post on Medium, Tumblr, and this site?  <br>If so,
              you may wonder how much it costs me to make it.  If your guess is "basically nothing,"<br>
              then you are correct!  Please consider supporting me on this Patreon, so that I can <br>
              achieve my current goal of raising $0 to continue producing content that costs me nothing<br>
              to produce.  Thank you!!

              <br>
              <br>
              Please look below to see just a sample of the exciting content that is available to people who donate<br>
              and also to people who do not donate
            </h3>
          </v-col>
          
          <v-row class="text-center">
            <v-col class="text-center" cols="6" sm="6">
              <v-card

                outlined
                tile
                class="justify-center"
              >
                <center><v-img :src="images.sample">
                  <div class="fill-height bottom-gradient"></div>
                </v-img></center>
                <v-card-title primary-title class="justify-right" >
                    <v-btn
                      rounded
                      color="primary"
                      dark
                      href="https://thoughtcatalog.com/evan-soohoo/2014/04/college-first-semester-vs-second-semester/"
                    >
                      Link to this post
                    </v-btn>
                  </v-card-title>
                  
              </v-card>   
            </v-col>
            <v-col class="text-center" cols="6" sm="6">
              <v-card

                outlined
                tile
                class="justify-center"
              >
                <center><v-img :src="images.sampleTwo">
                  <div class="fill-height bottom-gradient"></div>
                </v-img></center><br><br>
                <v-card-title primary-title class="justify-right" >
                  <br>
                  <br>
                  
                    <v-btn
                      rounded
                      color="primary"
                      dark
                      href="https://medium.com/@evan_soohoo/honest-reflections-five-years-of-dragon-boat-mostly-high-school-45e577c2580b"
                    >
                    
                      Link to this post
                    </v-btn>
                    
                    
                    
                    
                  </v-card-title>
                  
              </v-card>   
            </v-col>
          </v-row>       
  </v-container>
  </div>
</template>

<script>
export default {
  data () {
      return {
        dialog: false,
        multiLine: false,
        snackbarOne: false,
        snackbarTwo: false,
        snackbarThree: false,
        calmText: 'You can\'t actually donate, but thank you!',
        weirdText: 'You can\'t actually donate, and I couldn\'t figure out how to use v-layout in this.  v-snackbar works fine for some reason, but not v-layout',
        angryText: 'Donating is actually impossible, as this website has no server side, but thanks anyway!',
        images: {
                sample: require('.././assets/slackers.png'),
                sampleTwo: require('.././assets/medium.png'),
                computer: require('.././assets/picsummacbook.png')
            }
      }
    },
  name: 'Faketreon',
  props: {
    msg: String
  }
}
</script>

<!-- Add "scoped" attribute to limit CSS to this component only -->
<style scoped>
h3 {
  margin: 40px 0 0;
}

h4 {
  margin: 20px 0 0;
}
ul {

   margin:0 0 1em 15px;
  padding: 10;
  text-align: "right";
}
li {
  padding: 0;
  text-align: "center";
}
/*
ul {
  list-style-type: none;
  padding: 0;
}
li {
  display: inline-block;
  margin: 0 10px;
}
*/
a {
  color: #42b983;
}
</style>
