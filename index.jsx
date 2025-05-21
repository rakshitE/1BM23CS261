// app/courseView/index.jsx

import { View, Text } from 'react-native' 
import React from 'react'
import { useLocalSearchParams } from 'expo-router'
import Intro from '../../components/CourseView/Intro';
import { setBackgroundColorAsync } from 'expo-system-ui';
import { Colors } from 'react-native/Libraries/NewAppScreen';
import Chapters from '../../components/CourseView/Chapters';

export default function CourseView() {
    
    const { courseParams } = useLocalSearchParams();
    const course = JSON.parse(courseParams);

    return {
        <FlatList
            data={[]}
            ListHeaderComponent = {
                <View style = {{
                    flex: 1,
                    backgroundColor: Colors.WHITE
                }}>
                    <Intro course = {course} />
                    <Chapters course = {course} />
                </View>} />
    }
}