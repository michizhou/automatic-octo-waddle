import React, {Component} from 'react';
import {AppRegistry, View, Image, StyleSheet} from 'react-native';

class Logo extends Component {
  render() {
    return(
      <View style={styles.containerLogo}>
        <Image style ={styles.logo} source={require('./Images/rondeh_copy.png')}/>
      </View>
    );
  }
}

const styles = StyleSheet.create({
  containerLogo: {
    //flex: 1,
    alignItems: 'center',
    justifyContent: 'flex-start',
    paddingBottom: 300

  },
  logo: {
    width: 100,
    height: 100,
    opacity: 1
  }
})

export default Logo
