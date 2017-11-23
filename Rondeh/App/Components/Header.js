import React, { Component } from 'react';
import { StyleSheet, Text, View, Dimensions } from 'react-native';
class Header extends Component {
  constructor(props) {
    super(props);
    this.state = {
    };
  }
  render() {
    return(
      <View style={styles.header}>
        <Text style={styles.title}>Roam. Discover. Live</Text>
      </View>
    );
  }
}

const styles = StyleSheet.create({
  header: {
    height: 60,
    width: Dimensions.get('window').width,
    flexDirection: 'row',
    backgroundColor: '#9f1279',
    alignItems: 'center',
    justifyContent: 'center',
    opacity: 30,
    borderWidth: 1

  },
  title: {
    color: '#B6B6B6',
    fontSize: 18
  }
});

export default Header
