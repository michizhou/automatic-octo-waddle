import React, {Component} from 'react';
import {View, Text, StyleSheet, TextInput, Image} from 'react-native';
import SearchBar from './Search'
import Header from './Header'
import Logo from './Logo'
//import Background from './Back'

var styles = StyleSheet.create({
  container: {
    flex: 1,
    justifyContent: 'center',
    alignItems: 'center',
    width: null,
    height: null,
    opacity: 60
    //resizeMode: 'contain'
    //backgroundColor: 'gray',
  }
});

class Main extends Component {
  constructor(props) {
    super(props);
    this.state = {
    };
  }
  render() {
    return(
      <Image source={require('./Images/back1.png')} style={styles.container}>
      <Image source={'./Images/back1.png'}>
        <Logo />
        <Header />
        <SearchBar />
        </Image>
      </Image>
    );
  }
};

export default Main
